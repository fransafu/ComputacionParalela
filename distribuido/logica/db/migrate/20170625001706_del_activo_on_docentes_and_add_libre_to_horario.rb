class DelActivoOnDocentesAndAddLibreToHorario < ActiveRecord::Migration[5.0]
  def change
    remove_column :cursos, :asignado
    remove_column :docentes, :activo
    add_column :horarios , :libre, :boolean, default: true
  end
end
