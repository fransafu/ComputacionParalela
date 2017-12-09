class ModifacionHorarios < ActiveRecord::Migration[5.0]
  def change
    remove_column :horarios, :curso_asignatura
    remove_column :horarios , :nombre_asignatura
  end
end
