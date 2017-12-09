class RemoveLibreToDisponibilidadDocentes < ActiveRecord::Migration[5.0]
  def change
    remove_column :disponibilidad_docentes, :libre
  end
end
