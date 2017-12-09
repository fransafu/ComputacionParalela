class ChangeAsignacionesRemoveAsignatura < ActiveRecord::Migration[5.0]
  def change
    remove_column :asignaciones , :asignatura_id
  end
end
